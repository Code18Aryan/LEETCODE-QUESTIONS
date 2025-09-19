class Spreadsheet {
public:

    vector<vector<int>> grid;

    Spreadsheet(int rows) {
        
        grid.resize(26, vector<int>(rows,0));
    }

    pair<int,int> getRowCol(string cell){

        int col = cell[0] - 'A';
        string rowString = "";

        for(int i=1; i<cell.size(); i++){

            rowString += cell[i];
        }

        int row = stoi(rowString);

        return {col,row-1};
    }
    
    void setCell(string cell, int value) {
        
        pair<int,int> p = getRowCol(cell);
        grid[p.first][p.second] = value;
    }
    
    void resetCell(string cell) {
        
        pair<int,int> p = getRowCol(cell);
        grid[p.first][p.second] = 0;
    }
    
    int getValue(string formula) {
        
        string first = "", second = "";
        int i = 1, n = formula.size(), X = 0, Y = 0;

        while(i < n){

            while(i < n && formula[i] != '+'){

                first += formula[i];
                i++;
            }

            break;

        }

        i++;

        while(i < n){

            second += formula[i];
            i++;
        }

        if(first[0] >= 'A' && first[0] <= 'Z'){

            pair<int,int> p = getRowCol(first);
            X = grid[p.first][p.second];
        }

        else X = stoi(first);

        if(second[0] >= 'A' && second[0] <= 'Z'){

            pair<int,int> p = getRowCol(second);
            Y = grid[p.first][p.second];
        }

        else Y = stoi(second);

        return X + Y;


    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */