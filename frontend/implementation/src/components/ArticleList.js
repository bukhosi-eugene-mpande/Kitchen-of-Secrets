import React, { Component } from 'react';
import Article from './Article';
import DateForm from './DateForm';
import PropTypes from 'prop-types';

class ArticleList extends Component {
  constructor(props) {
    super(props);
    this.state = {
      selectedDate: this.props.theDate,
    };
  }

  handleDateChange = (newDate) => {
    this.setState({ selectedDate: newDate });
  };

  render() {
    const { articles } = this.props;
    const { selectedDate } = this.state;
    const filteredArticles = articles.filter((article) => article.date === selectedDate);

    return (
      <div className="container mt-2">
        <DateForm
          selectedDate={selectedDate}
          onDateChange={this.handleDateChange}
        />
        <div className="row">
          {filteredArticles.map((article, index) => (
            <Article key={index} article={article} />
          ))}
        </div>
      </div>
    );
  }
}

ArticleList.propTypes = {
  articles: PropTypes.arrayOf(
    PropTypes.shape({
      name: PropTypes.string.isRequired,
      description: PropTypes.string.isRequired,
      date: PropTypes.string.isRequired,
    })
  ).isRequired,
  theDate: PropTypes.string.isRequired,
};

export default ArticleList;
