class Solution {
public:

    int maxArea (vector<int>row){
        stack<int>s;
        int result = 0,x,area;
        int i=0;
        while(i<row.size()){
            if(s.empty() || row[s.top()] <= row[i])
                s.push(i++);
            else{
                x = s.top();
                s.pop();
                area = (row[x])*i;
                if(!s.empty)
                    area = (row[x]) * (i-s.top()-1);
                result = max(result,area);

            }
        }
        while(!s.empty()){
            x = s.top();
            s.pop();
            area = (row[x])*i;
            if(!s.empty)
                area = (row[x]) * (i-s.top()-1);
            result = max(result,area);

        }

        return result;
    }

    int maximalRectangle(vector<vector<char>>& mat) {

        vector<vector<int>>matrix;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]=='1')
                    matrix[i].push_back(1);
                else
                    matrix[i].push_back(0);
            }
        }

        int result = maxArea(matrix[0]);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j])
                    matrix[i][j]+=matrix[i-1][j];
                result = max(result,matrix[i]);
            }
        }
        return result; 
        
    }
};