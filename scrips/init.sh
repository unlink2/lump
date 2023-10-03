#!/bin/bash

# rename to project specific values
NAME="lump"
CONST="lump"
STRUCT="lump"
FN="lump"

# will be replaced
lump_NAME="lump"
lump_STRUCT="lump"
lump_CONST="lump"
lump_FN="lump"

function replace() {
	echo "Replacing $1 with $2"
	find ./ -type f -name '*.c' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.h' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.md' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.lua' -exec sed -i "s/$1/$2/g" {} \;
	find ./ -type f -name '*.sh' -exec sed -i "s/$1/$2/g" {} \;
	find ./doc/ -type f -name '*' -exec sed -i "s/$1/$2/g" {} \;
}

replace $lump_NAME $NAME
replace $lump_CONST $CONST
replace $lump_STRUCT $STRUCT
replace $lump_FN $FN

mv "include/$lump_NAME.h" "include/$NAME.h"
mv "src/$lump_NAME.c" "src/$NAME.c"
mv "doc/$lump_NAME" "doc/$NAME" 
