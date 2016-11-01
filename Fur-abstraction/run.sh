MPPADIR=/usr/local/k1tools

$MPPADIR/bin/k1-jtag-runner --multibinary=output/bin/Fur_abstraction.img --exec-multibin=IODDR0:master -- $1
