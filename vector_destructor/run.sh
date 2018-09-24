#!/bin/bash
set -euxv

readonly OUTPUT_PATH='out'
readonly REPEATE_NUM=2

function test() {
  local no=$1

  local outdir="${OUTPUT_PATH}/${no}"

  mkdir -p ${outdir}
  cp -p 'main.cc' "${outdir}/source.cc"
  make
  valgrind --leak-check=full './a.out' 2> "${outdir}/valgrind.txt"
}

function main() {
  rm -rf ${OUTPUT_PATH}

  git checkout "main.cc"

  for i in $(seq 0 ${REPEATE_NUM}); do
    if [ ${i} -ne 0 ]; then
      patch -p1 < "change${i}.patch"
    fi
    test ${i}
  done

  for i in $(seq ${REPEATE_NUM} -1 1); do
    patch -p1 -R < "change${i}.patch"
  done
}

main "$@"
