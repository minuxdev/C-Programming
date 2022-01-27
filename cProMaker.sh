#!/bin/zsh

echo "What program you wanna build?  "
read dir_name

parent_dir="c_projects"

if [[ "${PWD: -9}" != "Documents" ]]
then
    cd "~/Documents/"
fi


if [ ! -d "$parent_dir" ]
then
    mkdir "$parent_dir"
fi

cd "$parent_dir"

if [ ! -d "$dir_name" ]
then
    file_name=$(find `cd ~; pwd` |grep "$dir_name")
    echo $(file "$file_name")

    if [ -f "$file_name" ]
    then
        
        for f in `cat "$file_name"`;
        do 
            if [ ! -d "$f" ]
            then
                mkdir "$f"
                cd $f
                touch "$f".c
                cd -
                echo "$f" 'was created!'
            fi
        done
    else
        mkdir $dir_name
        cd $dir_name
        touch "$dir_name".c
        cd ..; 
        echo "Dir estructure created!"
    fi
fi

echo "Do you wanna open it now? [y/n]"
read opt

while;
do
    if [[ "$opt" != 'y' && "$opt" != 'n' ]]
    then 
        echo "Invalid option, enter 'y' or 'n'"
        read opt
        continue
    else
        if [ "$opt" = 'y' ]
        then 
            code .
        else
            break
        fi
    fi
done
