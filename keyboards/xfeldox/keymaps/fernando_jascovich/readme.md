# Custom keymap for minidox

## Building / Flashing

Use the following command:
```
docker run -ti --privileged -v /dev:/dev -v "$PWD":/qmk_firmware qmk-build make xfeldox:fernando_jascovich:avrdude
```
