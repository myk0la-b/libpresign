## [1.2.3](https://github.com/myk0la-b/libpresign/compare/v1.2.2...v1.2.3) (2025-07-26)

### Bug Fixes

* **ci:** replace pytest with simple import test in cibuildwheel ([5c1e424](https://github.com/myk0la-b/libpresign/commit/5c1e42487c0897ed28057d316f773921dc4da563))

## [1.2.2](https://github.com/myk0la-b/libpresign/compare/v1.2.1...v1.2.2) (2025-07-26)

### Bug Fixes

* **ci:** fix Linux OpenSSL installation in cibuildwheel ([5fdf9ca](https://github.com/myk0la-b/libpresign/commit/5fdf9ca5c2ec10dc7005d574f4c258f9a2cf7e3d))

## [1.2.1](https://github.com/myk0la-b/libpresign/compare/v1.2.0...v1.2.1) (2025-07-26)

### Bug Fixes

* **ci:** update cibuildwheel and fix Windows environment variable ([d97827a](https://github.com/myk0la-b/libpresign/commit/d97827a1a0345d73ab48ed4636262802b778db85))

## [1.0.1](https://github.com/myk0la-b/libpresign/compare/v1.0.0...v1.0.1) (2025-07-26)

### Bug Fixes

* **ci:** use GitHub App token for workflow dispatch ([f8c5e6b](https://github.com/myk0la-b/libpresign/commit/f8c5e6b8d1cb6887046247217f605ef188a1a844))

## 1.0.0 (2025-07-26)

### Features

* add Python stable ABI support for multi-version compatibility ([c72cdc0](https://github.com/myk0la-b/libpresign/commit/c72cdc0be7f708cddfebdb78949f3ff7e0356dbd))
* **ci:** add comprehensive GitHub Actions workflows ([9459ce9](https://github.com/myk0la-b/libpresign/commit/9459ce925a66fbb865b6d0d76f4abd3ff5c03740))
* **typing:** add type stubs and improve type checking ([89084ad](https://github.com/myk0la-b/libpresign/commit/89084ad8ae62989d11f35ec2f50c8fd26107fdc9))

### Bug Fixes

* **ci:** add missing semantic-release dependencies and configuration ([228e755](https://github.com/myk0la-b/libpresign/commit/228e755e8e6f0755db26514ebe9b6f70410cb077))
* **ci:** install uv and dependencies in release workflow ([3df1b78](https://github.com/myk0la-b/libpresign/commit/3df1b78f401d1542ffb8b563fedddc369906d704))
* **ci:** use --system flag for uv pip install in CI ([31725ae](https://github.com/myk0la-b/libpresign/commit/31725aef362e749be18c7e0067b6a511e48f2382))
* **ci:** use uv pip install instead of uv sync in release workflow ([fa271b2](https://github.com/myk0la-b/libpresign/commit/fa271b243ab8bcfd31e06ad21d6b0f41e5cdd39b))

### Documentation

* add initial changelog ([1f54db6](https://github.com/myk0la-b/libpresign/commit/1f54db6f09d46761abd937228146eddbb8de3d18))
* add migration and development guides ([73601f5](https://github.com/myk0la-b/libpresign/commit/73601f50e1fcd9f05c8a640486042b48b738090e))
* add MkDocs documentation with Material theme ([c819aba](https://github.com/myk0la-b/libpresign/commit/c819aba85d6af57f144f05c871fac49faf47a2eb))
* modernize README with comprehensive documentation ([68a9db0](https://github.com/myk0la-b/libpresign/commit/68a9db018db2d9e5a822cf4a3239653a893b33ba))

### Build System

* add build scripts for local development ([23b4e6b](https://github.com/myk0la-b/libpresign/commit/23b4e6b6e5ca0f2ee23a99a44bbc7f20c18ae437))
* add modern CMake configuration with scikit-build-core ([aff4ce7](https://github.com/myk0la-b/libpresign/commit/aff4ce7284ec5cb6f513162dd2e8d2036eb03b18))

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
