#include <iostream>
#include <vector>

using namespace std;

struct Point {
	double x, y, z;
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

struct OctreeNode {
	Point center;
	double halfWidth;
	vector<Point> points;
	OctreeNode* children[8];
	OctreeNode(Point center, double halfWidth) : center(center), halfWidth(halfWidth) {
		for (int i = 0; i < 8; i++) {
			children[i] = nullptr;
		}
	}
};

class Octree {
public:
	Octree(Point center, double halfWidth) : root(new OctreeNode(center, halfWidth)) {}
	void insert(Point point) {
		insert(root, point);
	}
	vector<Point> query(Point center, double halfWidth) {
		vector<Point> result;
		query(root, center, halfWidth, result);
		return result;
	}
private:
	OctreeNode* root;
	void insert(OctreeNode* node, Point point) {
		if (node->points.size() < 10) {
			node->points.push_back(point);
		}
		else {
			if (node->children[0] == nullptr) {
				double hw = node->halfWidth / 2;
				node->children[0] = new OctreeNode(Point(node->center.x - hw, node->center.y - hw, node->center.z - hw), hw);
				node->children[1] = new OctreeNode(Point(node->center.x - hw, node->center.y - hw, node->center.z + hw), hw);
				node->children[2] = new OctreeNode(Point(node->center.x - hw, node->center.y + hw, node->center.z - hw), hw);
				node->children[3] = new OctreeNode(Point(node->center.x - hw, node->center.y + hw, node->center.z + hw), hw);
				node->children[4] = new OctreeNode(Point(node->center.x + hw, node->center.y - hw, node->center.z - hw), hw);
				node->children[5] = new OctreeNode(Point(node->center.x + hw, node->center.y - hw, node->center.z + hw), hw);
				node->children[6] = new OctreeNode(Point(node->center.x + hw, node->center.y + hw, node->center.z - hw), hw);
				node->children[7] = new OctreeNode(Point(node->center.x + hw, node->center.y + hw, node->center.z + hw), hw);
			}
			for (int i = 0; i < 8; i++) {
				if (contains(node->children[i], point)) {
					insert(node->children[i], point);
					break;
				}
			}
		}
	}
	bool contains(OctreeNode* node, Point point) {
		return (point.x >= node->center.x - node->halfWidth && point.x <= node->center.x + node->halfWidth &&
			point.y >= node->center.y - node->halfWidth && point.y <= node->center.y + node->halfWidth &&
			point.z >= node->center.z - node->halfWidth && point.z <= node->center.z + node->halfWidth);
	}
	void query(OctreeNode* node, Point center, double halfWidth, vector<Point>& result) {
		if (node == nullptr) {
			return;
		}
		if (node->children[0] == nullptr) {
			for (Point point : node->points) {
				if (contains(Point(center.x, center.y, center.z), halfWidth, point)) {
					result.push_back(point);
				}
			}
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (intersects(Point(center.x, center.y, center.z), halfWidth, node->children[i])) {
					query(node->children[i], center, halfWidth, result);
				}
			}
		}
	}
	bool intersects(Point center, double halfWidth, OctreeNode* node) {
		return (node->center.x - node->halfWidth <= center.x + halfWidth && node->center.x + node->halfWidth >= center.x - halfWidth &&
			node->center.y - node->halfWidth <= center.y + halfWidth && node->center.y + node->halfWidth >= center.y - halfWidth &&
			node->center.z - node->halfWidth <= center.z + halfWidth && node->center.z + node->halfWidth >= center.z - halfWidth);
	}
	bool contains(Point center, double halfWidth, Point point) {
		return (point.x >= center.x - halfWidth && point.x <= center.x + halfWidth &&
			point.y >= center.y - halfWidth && point.y <= center.y + halfWidth &&
			point.z >= center.z - halfWidth && point.z <= center.z + halfWidth);
	}
};

int main() {
	Octree octree(Point(0, 0, 0), 100);
	octree.insert(Point(10, 10, 10));
	octree.insert(Point(-10, -10, -10));
	octree.insert(Point(10, -10, 10));
	octree.insert(Point(-10, 10, -10));
	vector<Point> result = octree.query(Point(0, 0, 0), 20);
	for (Point point : result) {
		cout << "(" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
	}
	return 0;
}
