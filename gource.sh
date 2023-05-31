#!/bin/bash

# Set the path to your Gource repository
GOURCE_REPO="."

# Set the path to your custom background image
BACKGROUND_IMAGE="gource/background.png"

# Set the path to the directory containing contributor images
CONTRIBUTOR_IMAGES="gource/user_images"
DEFAULT_IMAGE="gource/default.png"

param=$1

if [ "$param" == "save" ]; then
    echo "Saving gource.prefs"
    # --background-image $BACKGROUND_IMAGE \
    gource $GOURCE_REPO \
        -f \
        --background-colour 000000 \
        --user-image-dir $CONTRIBUTOR_IMAGES \
        --default-user-image $DEFAULT_IMAGE \
        --auto-skip-seconds 1 \
        --font-colour FFFFFF \
        --highlight-dirs \
        --hide dirnames \
        --filename-time 2 \
        --key \
        --logo gource/logo.png \
        --title "Corewar" \
        --font-size 18 \
        --font-colour FFFFFF \
        --font-file gource/CooperBits.ttf \
        --highlight-colour FF0000  \
        --save-config gource/gource.prefs
    exit 0
else
    echo "Loading gource.prefs"
    gource --load-config gource/gource.prefs
    exit 0
fi
