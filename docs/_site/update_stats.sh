#!/bin/bash
set -e

mkdir -p _includes

echo "## 📊 Problem Statistics" > _includes/stats.md

for i in {00..18}; do
  dir=$(ls -d ${i}_*/ 2>/dev/null || true)
  if [ -n "$dir" ]; then
    count=$(find "$dir" -name "*.cpp" | wc -l)
    echo "- **${dir%/}**: $count solutions" >> _includes/stats.md
  fi
done