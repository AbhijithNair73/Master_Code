#!/bin/bash
SDK_VER=3801200

SDK_SHORT="${SDK_VER:0:4}"
url="url ="
name="name ="

ADK_URL="https://artifactory.verifone.com/artifactory/rms-dev-repositories/ADK/INTEGRATION/4.6.14.2-891/adk-full-4.6.12.2-891.zip"
GVR_NAME="dl.UX-release-${SDK_VER}-3.0.3-PCI1501.01-GVR-prod1.tgz"
GVR_URL="https://artifactory.verifone.com/artifactory/rms-dev-repositories/VOS/${SDK_SHORT}/${SDK_VER}/prod/dl.UX-release-${SDK_VER}-prod.tgz"
vossdk="https://artifactory.verifone.com/artifactory/rms-dev-repositories/VOS/${SDK_SHORT}/${SDK_VER}/sdk/vos-sdk-winx86-release-${SDK_VER}.zip"
vos2sdk="https://artifactory.verifone.com/artifactory/rms-dev-repositories/vos2/${SDK_SHORT}/${SDK_VER}/sdk/vos2-sdk-winx86-release-${SDK_VER}.zip"

vossrn="* [V/OS ${SDK_VER}](https://artifactory.verifone.com/artifactory/rms-dev-repositories/VOS/${SDK_SHORT}/${SDK_VER}/prod/)"
vosvatsrn="  [(VATS)](https://artifactory.verifone.com/artifactory/rms-dev-repositories/VOS/${SDK_SHORT}/${SDK_VER}/vats-prod/)"
vos2srn="* [V/OS 2 ${SDK_VER}](https://artifactory.verifone.com/artifactory/rms-dev-repositories/vos2/${SDK_SHORT}/${SDK_VER}/prod/)"
vos2vatsrn="  [(VATS)](https://artifactory.verifone.com/artifactory/rms-dev-repositories/vos2/${SDK_SHORT}/${SDK_VER}/vats-prod/)"

adklinereplaced="ADK/INTEGRATION"
voslinereplaced="vos-sdk-winx86-"
vos2linereplaced="vos2-sdk-winx86-"
gvrnamereplaced="PCI1501.01-GVR-prod1.tgz"
gvrosreplaced="prod/dl.UX-release"
vossrnreplaced=""
vosvatsrnreplaced=""
vos2srnreplaced=""
vos2vatsrnreplaced=""
adk_url="${url} ${ADK_URL}"
vossdk_url="${url} ${vossdk}"
vos2sdk_url="${url} ${vos2sdk}"
gvros_name="${name} ${GVR_NAME}"
gvros_url="${url} ${GVR_URL}"

echo $vossdk_url
echo $vos2sdk_url
echo $adk_url
echo $gvros_name
echo $gvros_url

sed -i "s|.*$adklinereplaced.*|${adk_url}|" dependencies.ini
sed -i "s|.*$voslinereplaced.*|${vossdk_url}|" dependencies.ini
sed -i "s|.*$vos2linereplaced.*|${vos2sdk_url}|" dependencies.ini
sed -i "s|.*$gvrnamereplaced.*|${gvros_name}|" dependencies.ini
sed -i "s|.*$gvrosreplaced.*|${gvros_url}|" dependencies.ini