#!/bin/sh

SRC_DIR=src

make_action() {
  (
  cd build;
  make;
  # run build file if return code 0
  if [[ $? == 0 ]]; then ./cpwite; fi
  )
}

make_action

# watch file changes (close file after writing)
inotifywait -e close_write --format '%w %f' -m -r $SRC_DIR |\
(
  while read path file; do
    #echo "The file '$file' changed in directory '$path'"
    if [[ $file =~ .*cpp$ || $file =~ .*h$ ]]; then
      #echo "cpp file"
      make_action
    fi
  done
)
