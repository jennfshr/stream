#!/bin/bash
log_file="stream-`hostname`.out"
app=./xroads-stream-avx512
$app >${log_file} 1>&2
err=$?
exit $err
