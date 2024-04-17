#!/bin/sh

# for (( i=1000; i<=3751; i++ )) ; do
for (( i=1001; i<=1400; i++ )) ; do
    ugly=$( printf "%04d\n" ${i} ) 
    pretty=$( printf "nid%06d\n" ${i} ) 
    cp -a templatedir $pretty
    pushd $pretty
    sbatch --job-name=hurt${ugly} --nodes=1 --time=16:00:00 --nodelist=${pretty} run.sh
    sleep 0.5
    popd
done

exit 0
