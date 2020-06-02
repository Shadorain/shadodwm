# relaunch DWM if the binary changes, otherwise bail

while true; do
    # Log stderror to a file 
    dwm 2> ~/.dwm.log
    # No error logging
    #dwm >/dev/null 2>&1
done


# csum=$(sha1sum $(which dwm))
# new_csum=""
# while true
# do
#     if [ "$csum" != "$new_csum" ]
#     then
#         csum=$new_csum
#         dwm
#     else
#         exit 0
#     fi
#     new_csum=$(sha1sum $(which dwm))
#     sleep 0.5
# done
