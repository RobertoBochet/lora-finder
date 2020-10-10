# LoRa Finder

[LoRa finder](https://github.com/RobertoBochet/lora-finder) is a system thought to localize low power beacon exploiting LoRa.

## Building system

The firmware can be built with the building system provided by [PlatformIO](https://platformio.org/).
The dependencies needed to build the firmware will be automatically downloaded by PlatformIO.

### Build firmware

You can build the firmware with the following command

```shell script
pio run -t build -e <target_board>
```

### Upload firmware

To upload firmware to the board you can use the following command

```shell script
pio run -t upload -e <target_board> --upload-port <target_port>
```

## Supported boards

The project is currently supported and tested for the following boards:

- [ttgo-lora32-v1](https://github.com/LilyGO/TTGO-LORA-V1)