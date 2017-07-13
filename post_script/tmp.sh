for file in $( ls . | grep .cpp$ ); do
    enscript --highlight=cpp -o tmp.ps ${file}
    ps2pdf tmp.ps ${file%.cpp}.pdf
    mv ${file%.cpp}.pdf pdf/
done
rm tmp.ps;


