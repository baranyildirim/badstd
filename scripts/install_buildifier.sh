#!/usr/bin/env bash
set -Eeuo pipefail
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd -P)

<< comment
    This script installs buildifier. Buildifier requires go to work.
comment


go install github.com/bazelbuild/buildtools/buildifier@latest