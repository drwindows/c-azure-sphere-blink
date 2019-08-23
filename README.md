# Sphere.Blink

> Azure Sphere sample script written in C that lets each LED of the Avnet Azure Sphere MT3620 Starter Kit board blink.

## Prerequirements

- Windows 10
- Visual Studio 2019
- Claimed Azure Avnet Azure Sphere MT3620 Starter Kit device
- Device must be set to debug mode

## Features

The runs in an `while(true)` loop that iterates over the green, red and blue LED which are mapped via their GPIO pins `8`, `9` and `10`.

## Usage

Clone or download the script, compile and deploy it to the Azure Sphere device.

## Keep in mind

This is a proof-of-concept app that's purely build for having fun! All features have room for improvements or could harm the hardware.

## Contributing

Feel free to improve the quality of the code. It would be great to learn more from experienced C#, UWP and IoT developers.

## Authors

Just me, [Tobi]([https://tscholze.github.io).


## Links

* Element 14 [product page](https://www.element14.com/community/community/designcenter/azure-sphere-modules?ICID=azure-spherekit-topbanner)
* Getting started guide from [Microsoft](https://docs.microsoft.com/en-us/azure-sphere/install/overview) Community
* Other [samples](https://github.com/Azure/azure-sphere-samples)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details.
Dependencies or assets maybe licensed differently.
