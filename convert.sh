#!/bin/bash

# Create index.md from every README.md inside docs/
find docs -type f -name "README.md" | while read file; do
  dir_path="$(dirname "$file")"
  folder_name="$(basename "$dir_path" | tr '_' ' ')"
  index_path="$dir_path/index.md"

  {
    echo "---"
    echo "title: \"$folder_name\""
    echo "nav_order: 1"
    echo "---"
    echo ""
    tail -n +2 "$file"
  } > "$index_path"

  echo "✅ Converted: $index_path"
done
