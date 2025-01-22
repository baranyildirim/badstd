#!/usr/bin/env bash
set -Eeuo pipefail
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd -P)

<< comment
    This script prints the latest bazel command log
comment


output_base=$(bazel info output_base)
cat "$output_base/command.log"