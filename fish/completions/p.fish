# Autocompletes folder names in the Projects directory for the p command.
# eg. p personal/elixir/advent-of-code
complete -c p -a "(cd ~/Projects; and find . -maxdepth 3 -type d)"
