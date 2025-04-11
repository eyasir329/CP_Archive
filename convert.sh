#!/bin/bash

# Create docs structure
mkdir -p docs/assets/{images,css}

# Process all folders
find src -type d -not -path '*/\.*' | while read dir; do
  target_dir="docs/${dir#src/}"
  mkdir -p "$target_dir"
  
  # Convert README.md to index.md
  if [ -f "$dir/README.md" ]; then
    echo "---" > "$target_dir/index.md"
    echo "title: $(basename "$dir" | tr '_' ' ')" >> "$target_dir/index.md"
    echo "---" >> "$target_dir/index.md"
    tail -n +2 "$dir/README.md" >> "$target_dir/index.md"
  fi
  
  # Copy .cpp files
  find "$dir" -maxdepth 1 -name '*.cpp' -exec cp {} "$target_dir/" \;
done

# Required for GitHub Pages
touch docs/.nojekyll