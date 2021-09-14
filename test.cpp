#include <vector>
#include <iostream>
#include <chrono> 
struct Segment
{
	int row;
	int colStart;
	int colStop;
};

std::vector<Segment> FlipVertically(const std::vector<Segment>& region, const int flipRow) {
	std::vector<Segment> flipedRegion;


	//Old code
	/*std::vector<Segment> tempRegion;
	for (const auto& a : region) {
		int distance = a.row - flipRow;
		tempRegion.push_back({flipRow - distance,a.colStart,a.colStop});
	}
	while (!tempRegion.empty()) {
		int min_row = tempRegion[0].row;
		int index = 0;
		for (int j = 0; j < tempRegion.size(); j++) {
			if (tempRegion[j].row < min_row) {
				min_row = tempRegion[j].row;
				index = j;
			}
		}
		flipedRegion.push_back(tempRegion[index]);
		tempRegion.erase(tempRegion.begin()+index);
	}*/

	//New code
	int minInd = region.size() - 1;
	while (minInd >= 0) {
		int curInd = minInd;
		int n = 1;
		for (int j = minInd - 1;j >= 0;j--) {
			if (region[j].row == region[curInd].row) {
				minInd = j;
				n++;
			}
			else {
				break;
			}
		}
		for (int k = minInd;k < minInd + n;k++) {
			int distance = region[k].row - flipRow;
			flipedRegion.push_back({ flipRow - distance,region[k].colStart,region[k].colStop });
		}
		minInd--;
	}

	/*for (int i = region.size() - 1;i >= 0;) {
		int minInd = i;
		int n = 1;
		for (int j = minInd - 1;j >= 0;j--) {
			if (region[j].row == region[i].row) {
				minInd = j;
				n++;
			}
			else {
				break;
			}
		}
		for (int k = minInd;k < minInd + n;k++) {
			int distance = region[k].row - flipRow;
			flipedRegion.push_back({ flipRow - distance,region[k].colStart,region[k].colStop });
		}
		i = minInd-1;
	}*/
	return flipedRegion;
}

int main(){
	
	std::vector<Segment> region{ {1,2,8},{2,1,3},{2,5,6} };
	std::vector<Segment> flipedRegion;
	std::cout << "Region:" << std::endl;
	for (const auto& a : region) {
		std::cout << a.row << ": " << a.colStart << "-" << a.colStop << ";\n";
	}
	std::cout << std::endl << "Fliped Region:" << std::endl;
	flipedRegion = FlipVertically(region,1);
	for (const auto& a : flipedRegion) {
		std::cout << a.row << ": " << a.colStart << "-" << a.colStop << ";\n";
	}
	return 0;
}