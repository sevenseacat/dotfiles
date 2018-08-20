# Defined in - @ line 0
function gleam-precheckin --description 'alias gleam-precheckin gleam-test; and bundle exec rake rubocop_ratchet:check'
	gleam-test; and bundle exec rake rubocop_ratchet:check $argv;
end
