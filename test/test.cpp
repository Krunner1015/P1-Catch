// #include <catch2/catch_test_macros.hpp>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <random>
// #include "Student.h"
// #include "AVLTree.h"
//
// // Name: Kaiden Bartrum
// // UFID: 21051160
//
// using namespace std;
//
// // the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
// TEST_CASE("Test 1", "[incorrect][insert]"){
// 	AVLTree tree;
// 	tree.insertStudent("Lorenzo", 12345678);
// 	tree.insertStudent("Jariel", 12345678);
// 	REQUIRE(tree.root->ID == 12345678);
// 	REQUIRE(tree.root->name == "Lorenzo");
// }
//
// TEST_CASE("Test 2", "[incorrect][null]"){
// 	AVLTree tree;
// 	tree.insertStudent("", 123);
// 	REQUIRE(tree.root == nullptr);
// }
//
// TEST_CASE("Test 3", "[incorrect][removeInorder]"){
// 	AVLTree tree;
// 	tree.insertStudent("Lorenzo", 12345678);
// 	tree.removeInorder(3);
// 	REQUIRE(tree.root->ID == 12345678);
// 	REQUIRE(tree.root->name == "Lorenzo");
// }
//
// TEST_CASE("Test 4", "[incorrect][remove]"){
// 	AVLTree tree;
// 	tree.insertStudent("Lorenzo", 12345678);
// 	tree.remove(87654321);
// 	REQUIRE(tree.root->ID == 12345678);
// 	REQUIRE(tree.root->name == "Lorenzo");
// }
//
// TEST_CASE("Test 5", "[incorrect][insert]"){
// 	AVLTree tree;
// 	tree.insertStudent("Lorenzo", 12345678);
// 	tree.insertStudent("Lorenzo", 12345678);
// 	REQUIRE(tree.root->ID == 12345678);
// 	REQUIRE(tree.root->name == "Lorenzo");
// }
//
// TEST_CASE("Test 6", "[insert]"){
// 	AVLTree tree;
// 	vector<Student*> studs;
// 	tree.insertStudent("Lorenzo", 12345678);
// 	tree.insertStudent("Jariel", 21436587);
// 	tree.insertStudent("Yabdielys", 87654321);
// 	tree.getInorder(tree.root, studs);
// 	vector<int> actualOutput;
// 	for (auto s : studs) {
// 		actualOutput.push_back(s->ID);
// 	}
// 	vector<int> expectedOutput = {12345678, 21436587, 87654321};
// 	REQUIRE(expectedOutput.size() == actualOutput.size());
// 	REQUIRE(actualOutput == expectedOutput);
// }
//
//
// TEST_CASE("Test 7", "[insert][rotation]"){
// 	AVLTree tree;
// 	vector<Student*> studs;
//
// 	SECTION("LL case") {
// 		tree.insertStudent("Jariel", 21436587);
// 		tree.insertStudent("Lorenzo", 12345678);
// 		tree.insertStudent("Yabdielys", 87654321);
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs[0]->ID < studs[1]->ID);
// 		REQUIRE(studs[1]->ID < studs[2]->ID);
// 	};
//
// 	SECTION("RR case") {
// 		tree.insertStudent("Yabdielys", 87654321);
// 		tree.insertStudent("Lorenzo", 12345678);
// 		tree.insertStudent("Jariel", 21436587);
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs[0]->ID < studs[1]->ID);
// 		REQUIRE(studs[1]->ID < studs[2]->ID);
// 	};
//
// 	SECTION("LR case") {
// 		tree.insertStudent("Jariel", 21436587);
// 		tree.insertStudent("Yabdielys", 87654321);
// 		tree.insertStudent("Lorenzo", 12345678);
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs[0]->ID < studs[1]->ID);
// 		REQUIRE(studs[1]->ID < studs[2]->ID);
// 	};
//
// 	SECTION("RL case") {
// 		tree.insertStudent("Yabdielys", 87654321);
// 		tree.insertStudent("Jariel", 21436587);
// 		tree.insertStudent("Lorenzo", 12345678);
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs[0]->ID < studs[1]->ID);
// 		REQUIRE(studs[1]->ID < studs[2]->ID);
// 	};
// }
//
// TEST_CASE("Test 8", "[insert][100]"){
// 	AVLTree tree;
// 	vector<Student*> studs;
// 	std::vector<int> expectedOutput, actualOutput;
//
// 	for (int i = 0; i < 100; i++) {
// 		int randomInput = rand();
// 		if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0) {
// 			expectedOutput.push_back(randomInput);
// 			tree.insertStudent("Random", randomInput);
// 		}
// 	}
//
// 	std::sort(expectedOutput.begin(), expectedOutput.end());
//
// 	for (int i = 0; i < 10; i++) {
// 		std::random_device rd;
// 		std::mt19937 gen(rd());
// 		std::uniform_int_distribution<> distr(0, 99 - i);
// 		int randInt = distr(gen);
// 		tree.removeInorder(randInt);
// 		expectedOutput.erase(expectedOutput.begin() + randInt);
// 	}
//
// 	tree.getInorder(tree.root, studs);
// 	for (auto s : studs) {
// 		actualOutput.push_back(s->ID);
// 	}
// 	REQUIRE(expectedOutput.size() == actualOutput.size());
// 	REQUIRE(expectedOutput == actualOutput);
// }
//
// TEST_CASE("Test 9", "[remove]") {
// 	AVLTree tree;
// 	tree.insertStudent("Lorenzo", 21436587);
// 	tree.insertStudent("Jariel", 12345678);
// 	SECTION("remove leaf") {
// 		tree.remove(12345678);
// 		REQUIRE(tree.root->ID == 21436587);
// 		REQUIRE(tree.root->name == "Lorenzo");
// 		vector<Student*> studs;
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs.size() == 1);
// 		REQUIRE(studs[0]->ID == 21436587);
// 		REQUIRE(studs[0]->name == "Lorenzo");
// 	}
// 	SECTION("remove node with one kid") {
// 		tree.insertStudent("Yabdielys", 87654321);
// 		tree.insertStudent("Kate", 98765432);
// 		tree.remove(87654321);
// 		vector<Student*> studs;
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs.size() == 3);
// 		REQUIRE(studs[0]->ID == 12345678);
// 		REQUIRE(studs[0]->name == "Jariel");
// 		REQUIRE(studs[1]->ID == 21436587);
// 		REQUIRE(studs[1]->name == "Lorenzo");
// 		REQUIRE(studs[2]->ID == 98765432);
// 		REQUIRE(studs[2]->name == "Kate");
// 	}
// 	SECTION("remove node with 2 kids (right)") {
// 		tree.insertStudent("Yabdielys", 87654321);
// 		tree.insertStudent("Kate", 98765432);
// 		tree.remove(21436587);
// 		REQUIRE(tree.root->ID == 87654321);
// 		REQUIRE(tree.root->name == "Yabdielys");
// 		vector<Student*> studs;
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs.size() == 3);
// 		REQUIRE(studs[0]->ID == 12345678);
// 		REQUIRE(studs[0]->name == "Jariel");
// 		REQUIRE(studs[1]->ID == 87654321);
// 		REQUIRE(studs[1]->name == "Yabdielys");
// 		REQUIRE(studs[2]->ID == 98765432);
// 		REQUIRE(studs[2]->name == "Kate");
// 	}
// 	SECTION("remove node with 2 kids (left)") {
// 		tree.insertStudent("Kate", 98765432);
// 		tree.insertStudent("Yabdielys", 87654321);
// 		tree.remove(21436587);
// 		REQUIRE(tree.root->ID == 87654321);
// 		REQUIRE(tree.root->name == "Yabdielys");
// 		vector<Student*> studs;
// 		tree.getInorder(tree.root, studs);
// 		REQUIRE(studs.size() == 3);
// 		REQUIRE(studs[0]->ID == 12345678);
// 		REQUIRE(studs[0]->name == "Jariel");
// 		REQUIRE(studs[1]->ID == 87654321);
// 		REQUIRE(studs[1]->name == "Yabdielys");
// 		REQUIRE(studs[2]->ID == 98765432);
// 		REQUIRE(studs[2]->name == "Kate");
// 	}
// }
//
// TEST_CASE("Test 10", "[removeInorder]") {
// 	AVLTree tree;
// 	tree.insertStudent("Lorenzo", 12345678);
// 	tree.insertStudent("Jariel", 21436587);
// 	tree.insertStudent("Yabdielys", 87654321);
// 	tree.removeInorder(1);
// 	vector<Student*> studs;
// 	tree.getInorder(tree.root, studs);
// 	REQUIRE(studs.size() == 2);
// 	REQUIRE(studs[0]->ID == 12345678);
// 	REQUIRE(studs[1]->ID == 87654321);
// }
//
// TEST_CASE("Test 11", "[height]") {
// 	AVLTree tree;
// 	REQUIRE(tree.getHeight() == 0);
// 	tree.insertStudent("Lorenzo", 12345678);
// 	REQUIRE(tree.getHeight() == 1);
// 	tree.insertStudent("Jariel", 21436587);
// 	REQUIRE(tree.getHeight() == 2);
// 	tree.insertStudent("Yabdielys", 87654321);
// 	REQUIRE(tree.getHeight() == 2);
// }