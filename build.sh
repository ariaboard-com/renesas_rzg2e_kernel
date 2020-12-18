export ARCH="arm64"
export CROSS_COMPILE="aarch64-linux-gnu-"

if [ x"${CORES}" = x"" ]; then
    CORES=4
fi

WORKDIR="$(pwd)"

if [ x"$1" = x"mrprober" ]; then
   rm -rf "build"
fi

if [ ! -d "build" ]; then
    mkdir -p "build"
fi

if [ ! -f "build/${KNAME}/.config" ]; then
    cp arch/arm64/configs/novotech_defconfig "build/.config"
fi

make O="build" -j${CORES} Image
make O="build" -j${CORES} modules firmware
make O="build" renesas/r8a774c0-rzg2e-novotech.dtb

rm -rf "deploy"
mkdir -p "deploy"
mkdir -p "deploy/modules"

cp "build/arch/arm64/boot/Image" "deploy/"
cp "build/arch/arm64/boot/dts/renesas/"*.dtb "deploy/"
make O="build" modules_install INSTALL_MOD_PATH="${WORKDIR}/deploy/modules"

tar -czf deploy/modules.tar.gz -C deploy/modules .

