function git_info
	set -l repo_info (git rev-parse --git-dir HEAD 2>/dev/null)
	if test -n "$repo_info"
		if test $repo_info[2] != "HEAD"
			echo (set_color cyan) : (set_color purple)(git rev-parse --abbrev-ref HEAD) \((git rev-parse --short HEAD)\)
		else
			echo ""
		end
	else
		echo ""
	end
end

function fish_prompt
	test $SSH_TTY
    and printf (set_color red)$USER(set_color brwhite)'@'(set_color yellow)(prompt_hostname)' '
    test "$USER" = 'root'
    and echo (set_color red)"#"

    echo -n \n(set_color cyan).: (set_color green)(prompt_pwd)(git_info) (set_color cyan):.\n\$' '
end
