# Lines configured by zsh-newuser-install
HISTFILE=~/.zsh_history
HISTSIZE=1000
SAVEHIST=1000
setopt appendhistory autocd extendedglob histignorealldups nomatch notify sharehistory
unsetopt beep
bindkey -e
# End of lines configured by zsh-newuser-install

# The following lines were added by compinstall
zstyle :compinstall filename "$HOME/.zshrc"

autoload -Uz compinit
compinit
# End of lines added by compinstall

zstyle ':completion:*' menu select

source /usr/local/share/chruby/chruby.sh
source /usr/local/share/chruby/auto.sh

# Set up the prompt
fpath=(/usr/local/share/zsh-completions $fpath)
fpath+="$HOME/Projects/personal/dotfiles"

autoload -Uz promptinit
promptinit
setopt prompt_subst

prompt sevenseacat

alias be="bundle exec"
alias 'g?'="git status -s"
alias rdb="be rake db:{drop,create,migrate,seed,test:prepare}"
alias dirsize="du -sh"
alias gemnuke="gem uninstall -aIx"
alias serve="python -m SimpleHTTPServer 8000"
alias gb="git for-each-ref --sort=committerdate refs/heads/ --format='%(HEAD) %(color:yellow)%(refname:short)%(color:reset) | %(authorname) | (%(color:green)%(committerdate:relative)%(color:reset))| %(contents:subject) ' | column -t -s '|'"

export BUNDLER_EDITOR="sublime"
export EDITOR="sublime"
export ECTO_EDITOR="atom"
export HOMEBREW_NO_ANALYTICS=1
export LOLCOMMITS_DELAY=1
export PATH=$HOME/bin:./bin:${PATH}
export PATH="$HOME/.npm-packages/bin:$GOPATH/bin:$PATH"
export PATH="/usr/local/heroku/bin:$PATH"
export PATH="$PATH:$HOME/.yarn/bin"

# Fixes https://bugs.erlang.org/browse/ERL-251
export ERL_FLAGS="-run crypto"

export GPG_TTY=$(tty)

export LESS_TERMCAP_mb=$'\e'"[1;31m"
export LESS_TERMCAP_md=$'\e'"[1;31m"
export LESS_TERMCAP_me=$'\e'"[0m"
export LESS_TERMCAP_se=$'\e'"[0m"
export LESS_TERMCAP_so=$'\e'"[1;44;33m"
export LESS_TERMCAP_ue=$'\e'"[0m"
export LESS_TERMCAP_us=$'\e'"[1;32m"

# Load functions after aliases so they can use them
for file in $HOME/Projects/personal/dotfiles/functions/*; do
  source "$file"
done

# In order for gpg to find gpg-agent, gpg-agent must be running,
# and there must be an env variable pointing GPG to the gpg-agent socket.
# This little script, which must be sourced
# in your shell's init script (ie, .bash_profile, .zshrc, whatever),
# will either start gpg-agent or set up the
# GPG_AGENT_INFO variable if it's already running.

# Add the following
if [ -f ~/.gnupg/.gpg-agent-info ] && [ -n "$(pgrep gpg-agent)" ]; then
    source ~/.gnupg/.gpg-agent-info
    export GPG_AGENT_INFO
else
    eval $(gpg-agent --daemon --write-env-file ~/.gnupg/.gpg-agent-info)
fi
