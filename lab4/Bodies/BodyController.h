#pragma once

class CBody;

class CBodyController
{
public:
	CBodyController(std::istream& input, std::ostream& output, std::vector<std::shared_ptr<CBody>>& bodiesVector);
	bool HandleCommand();
	~CBodyController();

private:
	bool InfoAboutAllBodies(std::istream& args);
	bool AddBody(std::istream& args);
	bool GetBodyWithBiggestMass();
	bool GetLightestBodyInWater();

private:
	using Handler = std::function<bool(std::istream& args)>;

	using ActionMap = std::map<std::string, Handler>;

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;

	std::vector<std::shared_ptr<CBody>>& m_bodiesVector;
};