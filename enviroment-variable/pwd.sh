#!/bin/bash
RESULT_DIR=`pwd`/cgr_result
echo $RESULT_DIR

if [ -z "${PFM_PATH}" ]; then
    echo "PFM_PATH environment variable is undefined, so PMU will not record."
    # ./start_game.sh
else
    echo "Good."
    echo "${PFM_PATH}"
    echo "$PFM_PATH"
    #$PMF_PATH/pfm_multi/pfm_multi -e "instructions,cycles" ./start_game.sh
fi
