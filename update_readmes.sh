#!/bin/bash
for i in {00..18}; do
  dir=$(ls -d ${i}_* 2>/dev/null)
  if [ -n "$dir" ]; then
    cat > "$dir/README.md" <<EOF
---
layout: category
title: $(echo "$dir" | tr '_' ' ')
---

{% include problem_list.html category="$dir" %}
EOF
  else
    echo "Warning: Directory ${i}_* not found"
  fi
done