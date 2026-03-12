# openbrep-addon / CLAUDE.md

## 项目结构

- 这是 Archicad 29 的 C++ Add-on，内嵌 AI GDL 修复助手
- C++ 部分：`Sources/` 目录，负责 Archicad 面板 UI 和生命周期
- Python 后端：`copilot/` 目录，FastAPI 服务跑在 `localhost:8502`
- 后端复用 gdl-agent 的 LLMAdapter 和配置：`/Users/ren/MAC工作/工作/code/开源项目/gdl-agent`

## 关键路径

- Python 环境：`/Users/ren/miniconda3/bin/python`（conda base），禁止用 `/usr/bin/python3`
- Archicad Add-Ons 目录：`/Applications/GRAPHISOFT/Archicad 29/Add-Ons/`
- 版本号：`Sources/AddOnVersion.hpp` 的 `ADDON_VERSION` 宏
- 参考项目：`/Users/ren/tapir-archicad-automation`

## 构建与部署

- 唯一部署命令：`bash deploy.sh`（从项目根目录）
- `deploy.sh` 流程：`cmake --build build` → rm/cp bundle 到 AC29 → zip 打包 → `gh release create`
- 禁止 `cd build` 再 `make`，会导致路径变成 `build/build/...`

## 后端启动

- 正确启动：`cd ~/MAC工作/工作/code/开源项目/openbrep-addon && python -m uvicorn copilot.server:app --port 8502`
- C++ 侧会在面板打开时自动启动后端（`CopilotPalette.cpp`）
- 端口占用时：`lsof -ti:8502 | xargs kill -9`

## LLM 配置

- 配置文件：`/Users/ren/MAC工作/工作/code/开源项目/gdl-agent/config.toml`
- `model` 字段必须填具体模型名（如 `gpt-5.2-codex`），不能填 provider 别名
- `custom_providers` 支持自定义 OpenAI 兼容代理

## 开发原则

- 每次任务结尾：`git add -A && git commit && git push && bash deploy.sh`
- 复杂功能先拆最小步骤验证，不要一步到位
- 遇到 Archicad API 用法不确定，参考 `/Users/ren/tapir-archicad-automation`
