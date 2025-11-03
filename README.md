# Key Generator

A sophisticated C++ application for generating authentication keys through multiple endpoints with a minimalistic user interface.

## Features

- **Dual Tab Interface**: Separate tabs for External and Executor key generation
- **Minimalistic UI**: Clean, dark-themed interface with smooth animations
- **One-Click Generation**: Simple button-based key generation
- **Copy Functionality**: Instant clipboard copying of generated keys
- **Cross-Platform**: Compatible with Windows, Linux, and macOS

## Architecture

The application follows a modular architecture with clear separation of concerns:

```
KeyGenerator/
├── src/
│   ├── core/          # Core business logic and data processing
│   ├── ui/            # User interface components and rendering
│   ├── api/           # API endpoint handlers and network operations
│   └── main.cpp       # Application entry point
├── include/           # Common headers and dependencies
└── build/            # Build artifacts directory
```

## Requirements

### Dependencies
- **C++17** compatible compiler
- **libcurl** - HTTP client library
- **OpenGL** - Graphics rendering
- **GLFW** - Window management
- **Dear ImGui** - Immediate mode GUI
- **nlohmann/json** - JSON parsing library

### System Libraries
- OpenGL development libraries
- X11 development libraries (Linux)
- CMake 3.15 or higher


## Usage

1. **Launch the Application**:
   ```bash
   ./KeyGenerator
   ```

2. **Generate Keys**:
   - Select the desired tab (External or Executor)
   - Click "Generate Key" button
   - The generated key will appear below the button
   - Click "Copy" to copy the key to clipboard

3. **Key Information**:
   - Keys are generated via official API endpoints
   - Each key expires in 24 hours
   - No personal data is collected or stored

## API Endpoints

### External Key Generation
- **URL**: `https://extkey.valex.io/api/ext-keyauth/generate-direct`
- **Method**: POST
- **Headers**: Pre-configured with appropriate authentication
- **Response**: JSON containing key and expiration information

### Executor Key Generation
- **URL**: `https://key.valex.io/api/keyauth/generate-direct`
- **Method**: POST
- **Headers**: Pre-configured with appropriate authentication
- **Response**: JSON containing key and expiration information

## Project Structure

### Core Components
- **NetworkOperations**: Handles HTTP requests and responses
- **DataProcessing**: Parses JSON responses and extracts keys
- **ConnectionManager**: Manages curl sessions and configurations

### UI Components
- **ApplicationWindow**: Main window management and rendering loop
- **TabController**: Handles tab switching and content rendering
- **ComponentBuilder**: Creates UI elements with consistent styling

### API Handlers
- **ExternalKeyGenerator**: Specific implementation for external keys
- **ExecutorKeyGenerator**: Specific implementation for executor keys

## Troubleshooting

### Common Issues

1. **Missing Dependencies**:
   ```
   Error: Could not find package configuration file for glfw3
   ```
   Solution: Install GLFW development packages for your distribution.

2. **OpenGL Context Creation Failed**:
   ```
   Failed to create OpenGL context
   ```
   Solution: Update graphics drivers and ensure OpenGL 3.0+ support.

3. **Network Connection Issues**:
   ```
   Error: Could not generate key
   ```
   Solution: Check internet connection and firewall settings.

4. **Build Failures**:
   ```
   Undefined reference to curl_easy_init
   ```
   Solution: Ensure libcurl development packages are installed.

### Debug Mode
Enable debug output by building with:
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
```


## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## Security Notes

- The application uses secure HTTPS connections
- No sensitive data is stored locally
- All API communications are encrypted
- Regular dependency updates recommended

## Support

For issues and questions:
1. Check the Troubleshooting section
2. Review build logs for specific error messages
3. Ensure all dependencies are properly installed

## Version Information

- **Current Version**: 1.0.0 Early Access
- **C++ Standard**: C++17
- **Graphics API**: OpenGL 3.0+
- **Window Management**: GLFW 3.3+

---

*Note: This software is designed for legitimate key generation purposes. Users must comply with all applicable terms of service and laws.*
