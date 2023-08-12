# QT 6 Project Template

Project template for QT projects.

## Build

```bash
cmake -E make_directory build && cd build
cmake -G Ninja .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --parallel --config Release
ctest -C Release --output-on-failure --output-junit test-results.xml
cmake --install .
cmake --build . --config Release --target package
```
