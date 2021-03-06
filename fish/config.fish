source /usr/local/opt/asdf/asdf.fish

set -U BUNDLER_EDITOR sublime
set -U EDITOR nano
set -U HOMEBREW_NO_ANALYTICS 1

set -U KERL_CONFIGURE_OPTIONS "--without-javac --disable-hipe --with-ssl=(brew --prefix openssl)"
set -U CFLAGS "-O2 -g -fno-stack-check"

# Needed for commit signing in Git
set -x GPG_TTY (tty)
