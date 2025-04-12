#!/bin/bash
echo "## 📊 Problem Statistics" > docs/_includes/stats.md
for dir in docs/{00..18}_*; do
  count=$(find "$dir" -name "*.cpp" | wc -l)
  echo "- **$(basename "$dir")**: $count solutions" >> docs/_includes/stats.md
done