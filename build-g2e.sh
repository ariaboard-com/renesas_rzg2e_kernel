export WORKDIR="$(pwd)"

export ARCH="arm64"
export CROSS_COMPILE="${WORKDIR}/../gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-"

if [ x"${CORES}" = x"" ]; then
    CORES=4
fi

KNAME="g2e"

if [ x"$1" = x"mrprober" ]; then
   rm -rf "${WORKDIR}/build/${KNAME}" 2>/dev/null || true
fi

if [ ! -d "${WORKDIR}/build/${KNAME}" ]; then
    mkdir -p "${WORKDIR}/build/${KNAME}"
fi

if [ ! -f "build/${KNAME}/.config" ]; then
    cp arch/arm64/configs/novotech_defconfig "build/${KNAME}/.config"
fi

make O="build/${KNAME}" -j${CORES} Image
make O="build/${KNAME}" -j${CORES} modules firmware
make O="build/${KNAME}" renesas/r8a774c0-rzg2e-novotech.dtb

rm -rf "deploy/${KNAME}" 2>/dev/null || true
mkdir -p "deploy/${KNAME}"
mkdir -p "deploy/${KNAME}/modules"
mkdir -p "deploy/${KNAME}/openwrt-modules/lib/modules"

cp -v "build/${KNAME}/arch/arm64/boot/Image" "deploy/${KNAME}/"
cp -v "build/${KNAME}/arch/arm64/boot/dts/renesas/"*.dtb "deploy/${KNAME}/"
make O="build/${KNAME}" modules_install INSTALL_MOD_PATH="${WORKDIR}/deploy/${KNAME}/modules" INSTALL_MOD_STRIP=1

RELEASE_NAME=$(basename "deploy/${KNAME}/modules/lib/modules/"*)
OPENWRT_MODULE_DIR="deploy/${KNAME}/openwrt-modules/lib/modules/${RELEASE_NAME}"
mkdir -p "${OPENWRT_MODULE_DIR}"

find ${WORKDIR}/deploy/${KNAME}/modules/ -name "*.ko" -exec cp {} "${OPENWRT_MODULE_DIR}" \;

tar -czf deploy/${KNAME}/modules.tar.gz -C deploy/${KNAME}/modules . --owner=0 --group=0
tar -czf deploy/${KNAME}/openwrt-modules.tar.gz -C  deploy/${KNAME}/openwrt-modules . --owner=0 --group=0
