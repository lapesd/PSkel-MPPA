cmd_output/bin/Fur_abstraction.img := pushd output/bin > /dev/null; /usr/local/k1tools/bin/k1-create-multibinary  --clusters slave  --clusters-names slave       --boot master  -T Fur_abstraction.img -f  ; popd > /dev/null
