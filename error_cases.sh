#!/bin/bash

EXEC="./push_swap"

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"
WHITE="\e[0m"

PAD=40
TMP=tmp

function OK { printf "${GREEN}[OK]${WHITE}\n" ;}
function KO { printf "${RED}[KO]${WHITE}\n" ;}

# No args
function checkNoArgs
{
	printf $CYAN
	printf "#################################################################\n"
	printf "#                         CHECK NO ARGS                         #\n"
	printf "#################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC"
	if $EXEC > /dev/null 2>&1
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"\""
	if $EXEC "" > /dev/null 2>&1
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"           \""
	if $EXEC "           " > /dev/null 2>&1
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"   \" \"     \""
	if $EXEC "   " "     " > /dev/null 2>&1
	then
		OK
	else
		KO
	fi
}

# Not digital
function checkNotDigital
{
	printf $CYAN
	printf "################################################################\n"
	printf "#                    CHECK NOT DIGITAL ARGS                    #\n"
	printf "################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC abc"
	if $EXEC abc 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC 1 2 3%*"
	if $EXEC 1 2 3%* 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC 1 2 3 lol"
	if $EXEC 1 2 3 lol 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"-\" \"5 42\""
	if $EXEC "-" "5 42" 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"1 2\" \"3\" \"@#$%^\""
	if $EXEC "1 2" "3" "@#$%^" 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi
}

# Values higher than INT_MAX or lower than INT_MIN
function checkOverLimitsInt
{
	printf $CYAN
	printf "################################################################\n"
	printf "#                       CHECK INT LIMITS                       #\n"
	printf "################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC 2147483648"
	if $EXEC 2147483648 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"   -2147483649\""
	if $EXEC "   -2147483649" 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"4294967295   \""
	if $EXEC "4294967295   " 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"  -9223372036854775808  \""
	if $EXEC "  -9223372036854775808  " 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC -18446744073709551615"
	if $EXEC "-18446744073709551615" 2>&1 | grep --quiet "Error"
	then
		OK
	else
		KO
	fi
}

function checkNotUniq
{
	printf $CYAN
	printf "#################################################################\n"
	printf "#                      CHECK NOT UNIQ ARGS                      #\n"
	printf "#################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC 1 2 3 4 5 6 7 8 9 1"
	if $EXEC 1 2 3 4 5 6 7 8 9 1 2>&1 | grep --quiet "Error" 2>&1
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"-001 02\" \"3 4 5 6 7 8 9\" -1"
	if $EXEC "-001 2" "3 4 5 6 7 8 9" -1 2>&1 | grep --quiet "Error" 2>&1
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC \"-000\" \"+0\""
	if $EXEC "-000" "+0" 2>&1 | grep --quiet "Error" 2>&1
	then
		OK
	else
		KO
	fi
}

function checkStderr
{
	printf $CYAN
	printf "#################################################################\n"
	printf "#                      CHECK STDERR OUTPUT                      #\n"
	printf "#################################################################\n"
	printf $WHITE

	printf "%-*s: " $PAD "$EXEC 1 2 3 4 5 6 7 8 9 1"
	if $EXEC 1 2 3 4 5 6 7 8 9 1 > /dev/null 2>$TMP ; grep --quiet "Error" $TMP
	then
		OK
	else
		KO
	fi

	printf "%-*s: " $PAD "$EXEC abc"
	if $EXEC abc > /dev/null 2>$TMP ; grep --quiet "Error" $TMP
	then
		OK
	else
		KO
	fi

	rm $TMP
}

make push_swap

checkNoArgs
checkNotDigital
checkOverLimitsInt
checkNotUniq
checkStderr

exit 0
