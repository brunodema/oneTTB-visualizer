#if defined(_WIN32) || defined(WIN32)
#define DLL_EXPORT __declspec(dllexport) // Exporting functions from DLL on Windows
#else
#define DLL_EXPORT __attribute__((visibility("default"))) // Exporting functions from shared library on Linux
#endif

// Function declaration
extern "C" DLL_EXPORT void UpdateNodeOnGUI()
{

};