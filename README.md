# Vision
This project contains a simple C project that tries to recognize image types. The primary reason this project exists is so I can get some experience with the C programming language.

## Planned features
* recognize the image type, if it is a supported type.
* be able to find the height and width of the image.
* pass a folder as a command line argument, and run every file through the program to see if it recognizes the type.

The following filetypes might later be implemented
* GIF
* DNG
* BMP

### Supported filetypes
* JPEG
* PNG
* GIF

## Usage
Example usage would be 
`./exe file ./assets/bitterbal.jpg -r`

Argument structure:  
`./exe ${action} ${arg0} ${flags}`

Available actions:
| name   	| description   	                                                    |
|--------	|---------------	                                                    |
| file   	| check the type of a single file.                                      |
| dir    	| pass a directory as following arg to check all files in the directory.|
| folder 	| alias for dir. 	                                                    |
| help   	| print help info.	                                                    |

Available flags:
| name   	| description   	                                                    |
|--------	|---------------	                                                    |
| r      	| resolution this flag will also print the inputted file(s) resolution. |


## License
Copyright 2018 Dries Meerman

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
