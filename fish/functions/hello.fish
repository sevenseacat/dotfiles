# Defined in - @ line 0
# Temporarily sets a language version for the current session using asdf.
# eg. hello ruby 2.3 -> sets ASDF_RUBY_VERSION to 2.3
function hello
	set -xg ASDF_(string upper $argv[1])_VERSION $argv[2]
end
