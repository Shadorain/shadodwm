killall flameshot
killall picom
killall sxhkd

sxhkd -c ~/dwm/sxhkdrc &
picom --experimental-backends &
feh --bg-scale --no-fehbg ~/Pictures/Backgrounds/cherry.jpg &
flameshot &
