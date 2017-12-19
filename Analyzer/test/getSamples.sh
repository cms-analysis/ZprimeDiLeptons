# CI Samples
lvals=( "1" "10" "16" "22" "28" "34" "100k" )
intf=( "Con" "Des" )
heli=( "LR" "LL" "RR" )

cat <<EOF > ci_2mu_samples.py
cito2musamples = {
EOF

cat <<EOF > ci_2e_samples.py
cito2esamples = {
EOF

for l in "${lvals[@]}"
do
    cat <<EOF >> ci_2mu_samples.py
    "Lam${l}": {
EOF
    cat <<EOF >> ci_2e_samples.py
    "Lam${l}": {
EOF
    for i in "${intf[@]}"
    do
        cat <<EOF >> ci_2mu_samples.py
        "${i}": {
EOF
        cat <<EOF >> ci_2e_samples.py
        "${i}": {
EOF
        for h in "${heli[@]}"
        do
            cat <<EOF >> ci_2mu_samples.py
            "${h}": [
EOF
            cat <<EOF >> ci_2e_samples.py
            "${h}": [
EOF
            echo "ci_Lam${l}TeV${i}${h}.progress"
            muquery="dataset dataset=/CITo2Mu*Lam${l}TeV${i}${h}*Corrected-v4/*/MINIAODSIM"
            elquery="dataset dataset=/CITo2E*Lam${l}TeV${i}${h}*Corrected-v4/*/MINIAODSIM"
            if [ "${l}" = "100k" ]
            then
                muquery="dataset dataset=/CIToMu*/pthapa-*MiniAod*_M*_L100K_${h}_${i}*/USER instance=prod/phys03"
                elquery="dataset dataset=/CIToDie*/pdong-Dielectron_100*TeV_miniAOD_M*_${h}_${i}*/USER instance=prod/phys03"
            elif [ "${l}" = "10" ]
            then
                :
                muquery="dataset dataset=/CITo*/szaleski-MuMu_miniAODSIM_${h}${i}M*_Use-*/USER instance=prod/phys03"
                elquery="dataset dataset=/CITo*Lam${l}/szaleski-EE_miniAODSIM*_${h}${i}M*_remade-*/USER instance=prod/phys03"
            elif [ "${l}" = "1" ]
            then
                muquery="dataset dataset=/CITo2Mu*Lam16TeV${i}${h}*Corrected-v3/*/MINIAODSIM"
                elquery="dataset dataset=/CITo2E*Lam16TeV${i}${h}*Corrected-v3/*/MINIAODSIM"
            fi
            echo "dasgoclient --query=\"${muquery}\"|egrep -v (test|Aug9)"
            res=$(dasgoclient --query=${muquery}|egrep -v (test|Aug9))
            echo "$res" 2>&1 |tee -a ci_2mu_samples.py
            # dasgoclient --query=${muquery} 2>&1 |tee -a ci_2mu_samples.py
            echo "dasgoclient --query=\"${elquery}\"|egrep -v (test|Aug9)"
            res=$(dasgoclient --query=${elquery}|egrep -v (test|Aug9))
            echo "$res" 2>&1 |tee -a ci_2e_samples.py
            # dasgoclient --query=${elquery} 2>&1 |tee -a ci_2e_samples.py

            cat <<EOF >> ci_2mu_samples.py
            ],
EOF
            cat <<EOF >> ci_2e_samples.py
            ],
EOF
        done
        cat <<EOF >> ci_2mu_samples.py
        },
EOF
        cat <<EOF >> ci_2e_samples.py
        },
EOF
    done
    cat <<EOF >> ci_2mu_samples.py
    },
EOF
    cat <<EOF >> ci_2e_samples.py
    },
EOF
done
cat <<EOF >> ci_2mu_samples.py
}
EOF
cat <<EOF >> ci_2e_samples.py
}
EOF

# DY samples
cat <<EOF > dy_2mu_samples.py
dyto2musamples = {
EOF

cat <<EOF > dy_2e_samples.py
dyto2esamples = {
EOF

echo "dy_Lam${l}TeV${i}${h}.progress"
muquery="dataset dataset=/DYTo2Mu*Corrected-v3/*/MINIAODSIM"
elquery="dataset dataset=/DYTo2E*Corrected-v3/*/MINIAODSIM"
echo "dasgoclient --query=\"${muquery}\"|egrep -v (test|Aug9)"
res=$(dasgoclient --query=${muquery}|egrep -v (test|Aug9))
echo "$res" 2>&1 |tee -a dy_2mu_samples.py
# dasgoclient --query=${muquery} 2>&1 |tee -a dy_2mu_samples.py
echo "dasgoclient --query=\"${elquery}\"|egrep -v (test|Aug9)"
res=$(dasgoclient --query=${elquery}|egrep -v (test|Aug9))
echo "$res" 2>&1 |tee -a dy_2e_samples.py
# dasgoclient --query=${elquery} 2>&1 |tee -a dy_2e_samples.py

cat <<EOF >> dy_2mu_samples.py
}
EOF
cat <<EOF >> dy_2e_samples.py
}
EOF

perl -pi -e 's?/DYTo?["/DYTo?g'                    dy_2*_samples.py
perl -pi -e 's?/CITo?["/CITo?g'                    ci_2*_samples.py
perl -pi -e 's?/MINIAODSIM?/MINIAODSIM", None],?g' ??_2*_samples.py
perl -pi -e 's?/USER?/USER", None],?g'             ??_2*_samples.py
