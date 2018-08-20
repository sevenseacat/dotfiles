# Defined in - @ line 0
function gleam-test --description 'alias gleam-test bundle exec rspec --tag ~integration --tag ~js --tag ~slow'
	bundle exec rspec --tag ~integration --tag ~js --tag ~slow $argv;
end
