# oneTTB-visualizer
A cross-platform GUI that can be used to represent oneTBB graphs in real time.

# Setup
## Dependencies
It is necessary to manually install the one-tbb library on the host before compiling the code: https://www.intel.com/content/www/us/en/developer/articles/tool/oneapi-standalone-components.html#onetbb.

If running on Windows, it seems that it is necessary to add the DLL folder of one-tbb to the PATH environment variable (something `C:\Program Files (x86)\Intel\oneAPI\tbb\2021.9.0\redist\intel64\vc14`). If this is not done properly, DEBUG mode execution could fail at runtime.

# Resources
## Avalonia UI
### Tutorials
Maybe I should start with this one: https://docs.avaloniaui.net/tutorials/music-store-app.