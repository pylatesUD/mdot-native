# mDot-native

Permite usar el framework de [mbed](https://os.mbed.com/) en el [Multitech-mDot-F411](https://os.mbed.com/platforms/MTS-mDot-F411/) para programar en C/C++ sobre el microcontrolador ARM que está integrado en el módulo. Se usa el entorno de desarrollo [PlatformIO](http://platformio.org/) que permite el desarrollo en varios IDEs como [vscode](https://code.visualstudio.com/Download), [Kdevelop](https://www.kdevelop.org/download) y [Atom.io](http://atom.io) ó en cualquier IDE junto con comandos de consola.

el proyecto está dividido en dos partes:
- las librerias [ISL29011](https://os.mbed.com/teams/Multi-Hackers/code/ISL29011/) y [libmdot-mbed5](https://os.mbed.com/teams/MultiTech/code/libmDot-mbed5/).
- un código de ejemplo para mDot/xDot: [Dot-Examples](https://www.google.com/url?q=https://os.mbed.com/teams/MultiTech/code/Dot-Examples/&sa=U&ved=0ahUKEwjkgvuYtZnYAhUlmeAKHZTJBzsQFggFMAA&client=internal-uds-cse&cx=005068852423125155704:gdwng-4isdi&usg=AOvVaw2VGL1AYaq35MVXDx_tSl_w).

## Librerias

Se usa la libreria [libmdot-mbed5](https://os.mbed.com/teams/MultiTech/code/libmDot-mbed5/) que es una versión estable de libmdot para mbed.

También se usa la libreria [ISL29011](https://os.mbed.com/teams/Multi-Hackers/code/ISL29011/) que la requiere el ejemplo de mDot/xDot.

### TODO:

- [ ] Integrar estas librerías en el registro de librerias de Platformio para que sea fácil usarlas.
- [ ] Eliminar el "Hardcode" para incluir directorios de cabeceras.

## Ejemplo

se puede modificar el archivo *example_config.h* para modificar que tipo de compilación se va a hacer (clase C, OTA, ABP, etc).
también el archivo *platformio.ini* contiene opciones interesantes para cambiar estos valores.
