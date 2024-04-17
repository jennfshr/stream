#!/bin/bash

app=./stream_wrapper.sh

srun --ntasks-per-node=1 --ntasks=$SLURM_JOB_NUM_NODES $app
err=$?

exit $err
