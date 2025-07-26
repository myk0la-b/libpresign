# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Modern build system using scikit-build-core and pyproject.toml
- Comprehensive test suite with 100% coverage requirement
- Performance benchmarks comparing with boto3
- Full type hints support with py.typed marker
- CI/CD workflows for automated testing, building, and releasing
- Documentation site with MkDocs
- Support for Python 3.13
- Automatic semantic versioning and changelog generation
- Development workflow with uv package manager
- Code formatting and linting with ruff
- Dependabot configuration for dependency updates

### Changed
- Migrated from 7 separate setup.py files to unified pyproject.toml
- Replaced manual build scripts with cibuildwheel
- Updated package structure to proper Python package (libpresign/)
- Modernized CMakeLists.txt for scikit-build-core compatibility
- Enhanced README with badges, examples, and clear documentation
- Improved error handling to raise SystemError consistently

### Removed
- Legacy setup.py files (setup_linux_amd.py, setup_macos_arm.py, etc.)
- Old Dockerfile-based build system
- definitions.py file
- MANIFEST.in file

### Fixed
- Import issues with C extension module
- Region parameter can now be None (defaults to us-east-1)
- Memory efficiency in batch URL generation

## [1.2.0] - Previous Release

### Added
- Support for custom S3 endpoints
- MinIO compatibility
- Thread-safe URL generation

### Performance
- 160x faster than boto3 for single URL generation
- Optimized memory usage (262 bytes per URL)

## [1.1.1] - Legacy Version

### Notes
- Last version before build system modernization
- Tagged as v1.1.1-legacy for reference

## [1.0.0] - Initial Release

### Added
- Core functionality for S3 presigned URL generation
- Python bindings for C++ implementation
- Support for all AWS regions
- Configurable expiration times
- Basic error handling

### Performance
- Initial benchmarks showing 100x+ speedup over boto3

[Unreleased]: https://github.com/myk0la-b/libpresign/compare/v1.2.0...HEAD
[1.2.0]: https://github.com/myk0la-b/libpresign/compare/v1.1.1...v1.2.0
[1.1.1]: https://github.com/myk0la-b/libpresign/compare/v1.0.0...v1.1.1
[1.0.0]: https://github.com/myk0la-b/libpresign/releases/tag/v1.0.0