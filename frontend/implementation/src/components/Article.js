import React from 'react';
import PropTypes from 'prop-types';

const Article = ({ article }) => {
  return (
    <div className="col-md-4">
      <div className="card mb-3">
        <div className="card-header">{article.name}</div>
        <div className="card-body">
          <p><strong>Description :</strong> {article.description}</p>
          <p><strong>Date :</strong> {article.date}</p>
        </div>
      </div>
    </div>
  );
};

Article.propTypes = {
    article: PropTypes.shape({
      name: PropTypes.string.isRequired,
      description: PropTypes.string.isRequired,
      date: PropTypes.string.isRequired,
    }).isRequired,
  };

export default Article;