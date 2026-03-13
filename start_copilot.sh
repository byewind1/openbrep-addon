#!/bin/bash
set -euo pipefail

cd "/Users/ren/MAC工作/工作/code/开源项目/openbrep-addon"
nohup /Users/ren/miniconda3/bin/python -m uvicorn copilot.server:app --port 8502 > /tmp/copilot.log 2>&1 &
