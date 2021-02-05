#ifndef CONNECTOR_H
#define CONNECTOR_H

namespace taswira {
	class Connector {
	public:
		Connector(void)
			:Row(0),
			Col(0)
		{  }

		Connector(int row, int col)
			:Row(row),
			Col(col)
		{  }

		Connector(const Connector& connector)
			:Row(connector.Row),
			Col(connector.Col)
		{  }

		~Connector(void)
		{  }

		Connector& operator = (const Connector& connector) {
			this->Row = connector.Row;
			this->Col = connector.Col;

			return (*this);
		}

		int& RowLocation(void) {
			return this->Row;
		}

		int& ColLocation(void) {
			return this->Col;
		}

	private:
		int Row;
		int Col;
	};
}

#endif // !CONNECTOR_H