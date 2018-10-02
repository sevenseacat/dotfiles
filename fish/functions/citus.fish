# Defined in - @ line 0
function citus --description 'alias citus env COMPOSE_PROJECT_NAME=citus docker-compose -f docker-compose.citus.yml up -d'
	env COMPOSE_PROJECT_NAME=citus docker-compose -f docker-compose.citus.yml up -d $argv;
end
