#!/bin/bash

# Configs
BINARY='../push_swap_abaurens/push_swap'
BINARY='./push_swap'
CHECKER='./checker'
MAKEFILE='./Makefile'
BUILD_LOG='./build.log'

MAX_TEST_COUNT='10000'
MAX_VALUE_COUNT='4294967295'

# Flags
DEBUGER_ACTIVE=0
POSITIVE=0
SHUFFLE=1
STOP_ON_ERR=1
PRINT_STATS=0
REBUILD=0
_HAVE_GEN_SIZE=0
_HAVE_TARGET_OPT=0

# Internal options
EDGE_MAX='2147483647'
EDGE_MIN='-2147483648'
GEN_SIZE=$1
TEST_COUNT=1
TARGET_OPCNT=0

DEBUG=0 # TODO: to be changed

# Internal variables
NUM_EXP='[+-]*[0-9]+'

function print_help() {

	local help="Usage:
  ./run_test -h
  ./run_test <genSize> <targetOpCount> <testCount> [-khpsdrR]

    <genSize>       => Number of values to be generated
    <testCount>     => Number of tests to be passed (default to 1 if ommited)
    <targetOpCount> => Target number of operation
    -h | --help)       => Print this help and exits
    -k | --keep-going) => Don't stops the tests upon failing
    -R | --rebuild)    => Force project rebuild
    -p | --positive)   => Only generate positive numbers
    -r | --reverse)    => numbers are in reverse order (default is shuffeled)
    -s | --stats)      => print statistics
    -d | --debugger)   => enable debugger"

	printf "%s\n" "$help"
	if [[ $1 != 0 ]]; then
		exit $1
	fi
}

function parse_args() {

	if [[ $1 =~ $NUM_EXP ]]; then
		_HAVE_GEN_SIZE=1
		GEN_SIZE=$1
		shift
		if [[ $GEN_SIZE -le 0 || $GEN_SIZE -gt "$MAX_VALUE_COUNT" ]]; then
			printf "\e[31merror\e[0m: invalid parametter: '$GEN_SIZE'\n"
			printf "        <genSize> must be a positive integer.\n"
			exit 1
		fi
	fi

	if [[ $1 =~ $NUM_EXP ]]; then
		_HAVE_TARGET_OPT=1
		TARGET_OPCNT=$1
		shift
		if [[ $TARGET_OPCNT -le 0 || $TARGET_OPCNT -gt "$MAX_VALUE_COUNT" ]]; then
			printf "\e[31merror\e[0m: invalid parametter: '$TARGET_OPCNT'\n"
			printf "        <targetOpCount> must be a positive integer.\n"
			exit 1
		fi
	fi

	if [[ $1 =~ $NUM_EXP ]]; then
		# second argument is a number
		if [[ $1 -le 0 || $1 -gt "$MAX_TEST_COUNT" ]]; then
			printf "\e[31merror\e[0m: invalid parametter: '$GEN_SIZE'\n"
			printf "        <testCount> must be a positive integer lower or equal to $MAX_TEST_COUNT.\n"
			exit 1
		fi
		TEST_COUNT=$1
		shift
	fi

	while [[ ! -z $1 ]]; do
		case $1 in
			'-h'|'--help')
				print_help;
				exit 0;
				;;
			'-R'|'--rebuild')
				REBUILD=1
				;;
			'-k' | '--keep-going')
				STOP_ON_ERR=0
				;;
			'-p'|'--positive')
				POSITIVE=1
				;;
			'-r'|'--reverse')
				SHUFFLE=0
				;;
			'-s'|'--stats')
				PRINT_STATS=1
				;;
			'-d'|'--debugger')
				DEBUGER_ACTIVE=1
				;;
			*)
				printf "\e[31merror\e[0m: invalid parametter: '$1'\n"
				print_help 1;
				;;
		esac
		shift
	done

	if [[ $_HAVE_GEN_SIZE -ne 1 || $_HAVE_TARGET_OPT -ne 1 ]]; then
		printf "\e[31merror\e[0m: missing parametter\n"
		print_help 1;
	fi
}

function build_project() {
	if [[ $REBUILD == 1 || ! -f "$BINARY" || ! -f "$CHECKER" ]]; then
		printf "Building project..."
		make -f "$MAKEFILE" all > "$BUILD_LOG" 2>&1
		if [[ $? -ne 0 ]]; then
			printf "\n         \e[4;5;31mCompilation Error !\e[0m\n    See $BUILD_LOG for more info.\n"
			exit 2
		else
			printf "\e[32mSuccess\e[0m\n"
		fi
	fi
}

function gen_numbers() {
	local max=$(($GEN_SIZE-1))
	local min=0

	if [[ POSITIVE -eq 0 ]]; then
		max=$(($GEN_SIZE/2))
		min=$(($max-($GEN_SIZE-1)))
	fi

	local nums=($(eval echo {$max..$min}))

	if [[ $SHUFFLE != 0 ]]; then
		nums=($(echo ${nums[*]} | tr ' ' '\n' | shuf | tr '\n' ' '))
	fi

	NUMBERS="${nums[*]}"
}

# 5   =>    12
# 100 =>  1500 |  1300 | 1100 |  900 |  700
# 500 => 11500 | 10000 | 8500 | 7000 | 5500

function single_test() {
	gen_numbers;

	if [[ $DEBUG -eq 1 ]]; then
		printf "\n [$NUMBERS] "
	fi
	local result=$($BINARY $NUMBERS)
	if [[ $? -ne 0 ]]; then
		exit
	fi
	local validity=$(echo "$result" | $CHECKER $NUMBERS | grep -io 'OK')
	local length=$(echo "$result" | wc -l)

	if [[ $length -gt $MAX_OPS ]]; then MAX_OPS=$length; fi
	if [[ $length -lt $MIN_OPS ]]; then MIN_OPS=$length; fi
	if [[ $length -gt $TARGET_OPCNT ]]; then
		OVER_COUNT=$(($OVER_COUNT+1))
		if [[ $STOP_ON_ERR -eq 1 ]]; then
			printf "\e[31merror\e[0m: Too many operations.\n"
			print_targeted_num "Operation count" $length $TARGET_OPCNT
			printf "List:\n$NUMBERS\n"
			exit 2
		fi
	else
		UNDER_COUNT=$(($UNDER_COUNT+1))
	fi

	AVERAGE_OPS=$(($AVERAGE_OPS+$length))

	if [[ $validity == "OK" ]]; then
		SUCCESSES=$(($SUCCESSES+1))
		if [[ $DEBUG -eq 1 ]]; then
			printf " \e[32m$validity\e[0m\n"
		fi
	else
		FAILURE=$(($FAILURE+1))
		printf " \e[31merror:\e[0m Result list not sorted\n"
		if [[ $STOP_ON_ERR -ne 0 ]]; then
			printf "Input list:\n$NUMBERS\n"
			exit 2
		fi
		echo
	fi
}

# argv:
#	1: value name
#	2: value to display
#	3: target value
function print_targeted_num() {
	local opcol='32'
	local int_average=$(echo "$2" | sed "s:\.[0-9]*::g")

	if [[ "$int_average" -gt "$3" ]]; then
		opcol='31'
	elif [[ "$int_average" -eq "$3" ]]; then
		opcol='38;2;255;128'
	fi

	printf "$1: \e[%sm%.1f/%d.0\e[0m\n" $opcol $2 $3
}

function test_project() {

	FAILURE=0
	SUCCESSES=0
	AVERAGE_OPS=0
	MAX_OPS=0
	MIN_OPS=2147483647
	OVER_COUNT=0
	UNDER_COUNT=0

	local i=0
	while [[ $i -lt $TEST_COUNT ]]; do
		if [[ $i -gt 0  && $DEBUG -ne 1 ]]; then printf "\e[1A"; fi
		i=$(($i+1))
		printf "Runing test $i/$TEST_COUNT"
		single_test
		printf "\n"
	done
	
	AVERAGE_OPS=$(echo "$AVERAGE_OPS.0 / $TEST_COUNT.0" | bc -l)

	printf "Passed tests: $SUCCESSES/$TEST_COUNT\n"

	local default_IFS=$IFS
	IFS=$(echo)
	print_targeted_num "Average operation count" $AVERAGE_OPS $TARGET_OPCNT
	print_targeted_num "Maximum operation count" $MAX_OPS $TARGET_OPCNT
	print_targeted_num "Minimum operation count" $MIN_OPS $TARGET_OPCNT
	printf "Over target: %d (%.2f%%)\n" $OVER_COUNT $(echo "$OVER_COUNT / $TEST_COUNT * 100" | bc -l)
	printf "Under target: %d (%.2f%%)\n" $UNDER_COUNT $(echo "$UNDER_COUNT / $TEST_COUNT * 100" | bc -l)
	IFS=$default_IFS
}

parse_args $@
build_project
test_project
exit 0;
